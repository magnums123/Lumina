#pragma once
#include "Event.h"

namespace Lumina
{

    class LUMINA_API KeyPressEvent : public Event
    {
    public:
        int key;
        EventType GetStaticType() const override { return EventType::KeyPress; };
        std::string &GetType() const override { return "KeyPressEvent"; };
    };

    class LUMINA_API KeyReleaseEvent : public Event
    {
    public:
        int key;
        EventType GetStaticType() const override { return EventType::KeyRelease; };
        std::string &GetType() const override { return "KeyReleaseEvent"; };
    };

} // namespace Lumina