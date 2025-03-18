#pragma once
// https://github.com/Rednick16/IL2Cpp-Dictionary/tree/main

template <typename T>
struct monoArray
{
    void* klass;
    void* monitor;
    void* bounds;
    int   max_length;
    T vector[65535];

    T& operator [] (int i)
    {
        return vector[i];
    }

    const T& operator [] (int i) const
    {
        return vector[i];
    }

    bool Contains(T item)
    {
        for (int i = 0; i < max_length; i++)
        {
            if (vector[i] == item) return true;
        }
        return false;
    }
};

template<typename T>
using Array = monoArray<T>;

template<typename TKey, typename TValue>
struct Il2CppDictionary
{
    struct KeysCollection;
    struct ValueCollection;

    struct Entry
    {
        int hashCode;
        int next;
        TKey key;
        TValue value;
    };

    void* kass;
    void* monitor;
    Array<int>* buckets;
    Array<Entry>* entries;
    int count;
    int version;
    int freeList;
    int freeCount;
    void* comparer;
    KeysCollection* keys;
    ValueCollection* values;
    void* _syncRoot;

    void* get_Comparer()
    {
        return comparer;
    }

    int get_Count()
    {
        return count;
    }

    KeysCollection get_Keys()
    {
        if (!keys) keys = new KeysCollection(this);
        return (*keys);
    }

    ValueCollection get_Values()
    {
        if (!values) values = new ValueCollection(this);
        return (*values);
    }

    TValue operator [] (TKey key)
    {
        int i = FindEntry(key);
        if (i >= 0) return (*entries)[i].value;
        return TValue();
    }

    const TValue operator [] (TKey key) const
    {
        int i = FindEntry(key);
        if (i >= 0) return (*entries)[i].value;
        return TValue();
    }

    int FindEntry(TKey key)
    {
        for (int i = 0; i < count; i++)
        {
            if ((*entries)[i].key == key) return i;
        }
        return -1;
    }

    bool ContainsKey(TKey key)
    {
        return FindEntry(key) >= 0;
    }

    bool ContainsValue(TValue value)
    {
        for (int i = 0; i < count; i++)
        {
            if ((*entries)[i].hashCode >= 0 &&
                (*entries)[i].value == value) return true;
        }
        return false;
    }

    bool TryGetValue(TKey key, TValue* value)
    {
        int i = FindEntry(key);
        if (i >= 0) {
            *value = (*entries)[i].value;
            return true;
        }
        *value = TValue();
        return false;
    }

    TValue GetValueOrDefault(TKey key)
    {
        int i = FindEntry(key);
        if (i >= 0) {
            return (*entries)[i].value;
        }
        return TValue();
    }

    struct KeysCollection
    {
        Il2CppDictionary* dictionary;

        KeysCollection(Il2CppDictionary* dictionary)
        {
            this->dictionary = dictionary;
        }

        TKey operator [] (int i)
        {
            auto entries = dictionary->entries;
            if (!entries) return TKey();
            return (*entries)[i].key;
        }

        const TKey operator [] (int i) const
        {
            auto entries = dictionary->entries;
            if (!entries) return TKey();
            return (*entries)[i].key;
        }

        int get_Count()
        {
            return dictionary->get_Count();
        }
    };

    struct ValueCollection
    {
        Il2CppDictionary* dictionary;

        ValueCollection(Il2CppDictionary* dictionary)
        {
            this->dictionary = dictionary;
        }

        TValue operator [] (int i)
        {
            auto entries = dictionary->entries;
            if (!entries) return TValue();
            return (*entries)[i].value;
        }

        const TValue operator [] (int i) const
        {
            auto entries = dictionary->entries;
            if (!entries) return TValue();
            return (*entries)[i].value;
        }

        int get_Count()
        {
            return dictionary->get_Count();
        }
    };
};