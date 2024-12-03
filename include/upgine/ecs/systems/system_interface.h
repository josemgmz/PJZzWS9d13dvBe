//
// Created by José Manuel Gómez on 29/01/2023.
//

#ifndef INCLUDE_UPGINE_ECS_SYSTEM_SYSTEM_INTERFACE_H_
#define INCLUDE_UPGINE_ECS_SYSTEM_SYSTEM_INTERFACE_H_

#include "upgine/macros/dependency_injector.h"
#include "upgine/core/managers/services_manager.h"

namespace Upgine::ECS::Systems
{
    class ISystem
    {
    public:
        virtual ~ISystem() = default;
        virtual void Update() = 0;
        virtual int GetPriority() const = 0;
    };
}

#endif //INCLUDE_UPGINE_ECS_SYSTEM_SYSTEM_INTERFACE_H_
