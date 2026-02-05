#pragma once
#include "Event.h"

namespace Lumina
{

    class LUMINA_API WindowCloseEvent : public Event
    {
    public:
        EventType GetStaticType() const override { return EventType::WindowClose; };
        std::string &GetType() const override { return "WindowCloseEvent"; };
    };

    class LUMINA_API WindowMoveEvent : public Event
    {
    public:
        int nPosx, nPosy;
        EventType GetStaticType() const override { return EventType::WindowMove; };
        std::string &GetType() const override { return "WindowMoveEvent"; };
    };

    class LUMINA_API WindowResizeEvent : public Event
    {
    public:
        int nSizex, nSizey;
        EventType GetStaticType() const override { return EventType::WindowResize; };
        std::string &GetType() const override { return "WindowResizeEvent"; };
    };

} // namespace Lumina