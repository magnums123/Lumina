#pragma once

#include <Lumina/Core.h>
#include <function>
#include <string>

namespace Lumina
{
  enum class EventType
  {
    None = 0,
    WindowClose,
    WindowResize,
    WindowMove,
    KeyPress,
    KeyRelease,
    MouseMove,
    MouseButtonPress,
    MouseButtonRelease,
    MouseScroll
  };

  class LUMINA_API Event
  {
  protected:
    bool Handled = false;

  public:
    virtual EventType GetStaticType() const = 0;
    virual std::string &GetType() const = 0;
  };

  class EventDispatcher
  {
    template <typename T>
    using EventFn = std::function<bool(T &)>;

  public:
    EventDispatcher(Event event);
  };

} // namespace Lumina
