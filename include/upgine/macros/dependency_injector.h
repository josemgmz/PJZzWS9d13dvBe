/*
MIT License

Copyright (c) 15/01/2023 Jose Manuel Gomez Castellana (josemgmz)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef INCLUDE_UPGINE_MACROS_DEPENDENCY_INJECTOR_H_
#define INCLUDE_UPGINE_MACROS_DEPENDENCY_INJECTOR_H_

#include "upgine/core/managers/services_manager.h"

#define INJECT_DEPENDENCY(Class, Dependency, DependencyName)                                  \
    private:                                                                                  \
        Dependency & dependency##DependencyName##_;                                           \
    protected:                                                                                \
        const Dependency & Get##DependencyName() { return dependency##DependencyName##_; }    \
    public:                                                                                   \
        Class() : dependency##DependencyName##_(Dependency::GetInstance()) { }


#define INJECT_DEPENDENCY_CONSTRUCTOR(Class, Dependency, DependencyName)          \
    private:                                                                                  \
        Dependency & dependency##DependencyName##_;                                           \
        void OnConstructor();                                                                 \
    protected:                                                                                \
        const Dependency & Get##DependencyName() { return dependency##DependencyName##_; }    \
    public:                                                                                   \
        Class() : dependency##DependencyName##_(Dependency::GetInstance()) { OnConstructor(); }


#define INJECT_DEPENDENCY_TEMPLATE(Class, Dependency, DependencyName)          \
    private:                                                                                  \
        Dependency & dependency##DependencyName##_;                                           \
    protected:                                                                                \
        const Dependency & Get##DependencyName() { return dependency##DependencyName##_; }    \
    public:                                                                                   \
        Class() : dependency##DependencyName##_(Dependency::GetInstance()) { OnConstructor(); }

#define INJECT_SERVICES(Class) \
    INJECT_DEPENDENCY(Class, Upgine::Core::Managers::ServicesManager, ServiceManager)

#define INJECT_SERVICES_CONSTRUCTOR(Class) \
    INJECT_DEPENDENCY_CONSTRUCTOR(Class, Upgine::Core::Managers::ServicesManager, ServiceManager)

#define INJECT_SERVICES_TEMPLATE(Class) \
    INJECT_DEPENDENCY_TEMPLATE(Class, Upgine::Core::Managers::ServicesManager, ServiceManager)

#endif //INCLUDE_UPGINE_MACROS_DEPENDENCY_INJECTOR_H_
