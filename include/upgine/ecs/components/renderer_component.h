/*
MIT License

Copyright (c) 23/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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

#ifndef INCLUDE_UPGINE_ECS_COMPONENTS_RENDERER_COMPONENT_H_
#define INCLUDE_UPGINE_ECS_COMPONENTS_RENDERER_COMPONENT_H_

#include "upgine/core/types/basic_types.h"
#include "component_interface.h"
#include "upgine/graphics/resources/constants.h"

namespace Upgine::ECS::Components
{
    struct Renderer : public IComponent
    {
    public:
        uint32 vertexBufferId;
        uint32 materialId;
        uint32 textureIds[Graphics::Resources::MAX_TEXTURES] ={
            UINT32_MAX , UINT32_MAX , UINT32_MAX , UINT32_MAX ,
            UINT32_MAX , UINT32_MAX , UINT32_MAX , UINT32_MAX};

        static const uint32 GetId() { return 0x02; }
    };
}

#endif //INCLUDE_UPGINE_ECS_COMPONENTS_RENDERER_COMPONENT_H_
