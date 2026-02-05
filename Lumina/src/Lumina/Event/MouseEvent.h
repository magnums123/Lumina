#pragma once
#include "Event.h"

namespace Lumina
{

    enum class ScrollDirection
    {
        None = 0,
        ScrollUp,
        ScrollDown
    };

    class LUMINA_API MouseMoveEvent : public Event
    {
    public:
        int x, y;
        EventType GetStaticType() const override { return EventType::MouseMove; };
        std::string &GetType() const override { return "MouseMoveEvent"; };
    };

    class LUMINA_API MouseButtonPress : public Event
    {
    public:
        int key;
        EventType GetStaticType() const override { return EventType::MouseButtonPress; };
        std::string &GetType() const override { return "MouseButtonPress"; };
    };

    class LUMINA_API MouseButtonRelease : public Event
    {
    public:
        int key;
        EventType GetStaticType() const override { return EventType::MouseButtonRelease; };
        std::string &GetType() const override { return "MouseButtonRelease"; };
    };

    class LUMINA_API MouseScrollEvent : public Event
    {
    public:
        ScrollDirection Direction;
        EventType GetStaticType() const override { return EventType::WindowResize; };
        std::string &GetType() const override { return "WindowResizeEvent"; };
    };

} // namespace Lumina