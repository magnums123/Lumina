#pragma once

namespace Lumina
{

enum class EventType
{
    None = 0,
    WindowClose,
    WindowResize,
    KeyPressed,
    KeyReleased,
    MouseMoved,
    MouseButtonPressed,
    MouseButtonReleased
};

class Event
{
  public:
    bool Handled = false;
    virtual EventType GetType() const = 0;
    virtual const char* GetName() const = 0;
};

class EventDispatcher
{
  public:
    EventDispatcher(Event& event) : m_Event(event) {}

    template <typename T, typename F>
    bool Dispatch(const F& func)
    {
        if (m_Event.GetType() == T::GetStaticType())
            {
                m_Event.Handled = func(static_cast<T&>(m_Event));
                return true;
            }
        return false;
    }

  private:
    Event& m_Event;
};

class KeyPressEvent : public Event
{
  public:
    int key, scancode, mods;
    static EventType GetStaticType() { return EventType::KeyPressed; }
    EventType GetType() const override { return GetStaticType(); }
    const char* GetName() const override { return "KeyPress"; }
};

class WindowCloseEvent : public Event
{
  public:
    static EventType GetStaticType() { return EventType::WindowClose; }
    EventType GetType() const override { return GetStaticType(); }
    const char* GetName() const override { return "WindowClose"; }
};

} // namespace Lumina
