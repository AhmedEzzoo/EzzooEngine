#pragma once
#include <sstream>
#include "event.h"

class KeyEventCategory : public Event
{

public:
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);
    int get_key_code() const { return m_key_code; }

protected:
    KeyEventCategory(int key_code) : m_key_code(key_code) {}

    int m_key_code;
};

class KeyPressedEvent : public KeyEventCategory
{

public:
    KeyPressedEvent(int key_code, int repeatedCount) : KeyEventCategory(key_code), m_repeatecount(repeatedCount) {}

    std::string to_string() const override
    {

        std::stringstream ss;

        ss << "KeyPressedEvent : " << (char)m_key_code << " (" << m_repeatecount << " repeats)";
        return ss.str();
    }

    EVENT_CLASS_TYPE(KeyPressed)

private:
    int m_repeatecount;
};

class KeyReleasedEvent : public KeyEventCategory
{

public:
    KeyReleasedEvent(int key_code) : KeyEventCategory(key_code) {}

    std::string to_string() const override
    {

        std::stringstream ss;
        ss << "KeyReleasedEvent : " << m_key_code;

        return ss.str();
    }

    EVENT_CLASS_TYPE(KeyReleased)
};

class KeyTypedEvent : public KeyEventCategory
{

public:
    KeyTypedEvent(int key_code) : KeyEventCategory(key_code) {}

    std::string to_string() const override
    {

        std::stringstream ss;

        ss << "Key Code is : " << m_key_code;

        return ss.str();
    }

    EVENT_CLASS_TYPE(KeytTyped);
};