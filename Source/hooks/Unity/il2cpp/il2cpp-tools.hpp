// il2cpp-tools.hpp

#pragma once
#include "il2cpp-api-functions.hpp"
#include "il2cpp_symbols.hpp"
#include "il2cpp-tabledefs.h"

namespace il2cpp {
    template<typename... T, typename R>
    inline Il2CppDelegate* CreateDelegateStatic(R(*fn)(void*, T...)) {
        auto delegate = reinterpret_cast<Il2CppDelegate*>(il2cpp_object_new(il2cpp_defaults.delegate_class));
        delegate->method_ptr = reinterpret_cast<Il2CppMethodPointer>(fn);

        const auto methodInfo = new MethodInfo{};
        methodInfo->name = "AnonymousStaticMethod";
        methodInfo->methodPointer = delegate->method_ptr;
        methodInfo->klass = il2cpp_defaults.mono_method_class;
        // methodInfo->invoker_method = GetInvokerMethod(fn, index_sequence_for<T...>{});
        methodInfo->slot = kInvalidIl2CppMethodSlot;
        methodInfo->flags = METHOD_ATTRIBUTE_STATIC;
        methodInfo->parameters_count = sizeof...(T);

        methodInfo->nativeFunction = reinterpret_cast<Il2CppMethodPointer>(fn);
        methodInfo->is_marshaled_from_native = true;

        delegate->method = reinterpret_cast<const MethodInfo*>(il2cpp_method_get_object(methodInfo, methodInfo->klass));
        // delegate->invoke_impl = methodInfo->invoker_method;

        return delegate;
    }

    template<typename R>
    inline Il2CppDelegate* CreateDelegateStatic(R(*fn)()) {
        return CreateDelegateStatic(reinterpret_cast<R(*)(void*)>(fn));
    }

    inline Il2CppObject* GetSingletonInstance(Il2CppClass* klass)
    {
        if (!klass || !klass->parent)
        {
            return nullptr;
        }
        auto instanceField = il2cpp_class_get_field_from_name(klass, "_instance");
        if (!instanceField)
        {
            instanceField = il2cpp_class_get_field_from_name(klass, "instance");
            if (!instanceField)
            {
                return nullptr;
            }
        }
        Il2CppObject* instance;
        il2cpp_field_static_get_value(instanceField, &instance);
        return instance;
    }

    class IEnumerator {
	private:
		Il2CppObject* enumerator;
    public:
        IEnumerator(Il2CppObject* enumerator) {
			this->enumerator = enumerator;
        }
        bool MoveNext() {
            auto moveNext = reinterpret_cast<bool(*)(Il2CppObject*)>(il2cpp_class_get_method_from_name(enumerator->klass, "MoveNext", 0)->methodPointer);
            return moveNext(enumerator);
        }
        Il2CppObject* GetCurrent() {
            auto getCurrent = reinterpret_cast<Il2CppObject * (*)(Il2CppObject*)>(il2cpp_class_get_method_from_name(enumerator->klass, "get_Current", 0)->methodPointer);
            return getCurrent(enumerator);
        };
    };


}