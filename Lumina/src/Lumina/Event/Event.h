#pragma once

#include <Lumina/Core.h>

namespace Lumina
{
enum class EventType
{
    None = 0,
    WindowClose,
    WindowResize,
    WindowMoved,
    KeyPress,
    KeyRelease,
    MouseMove,
    MouseButtonPress,
    MouseButtonRelease,
    MouseScroll
};

class LUMINA_API Event
{
  public:
    virtual EventType GetStaticType() const = 0;
};

} // namespace Lumina
