#include <iostream>
#include <string>
#include <vector>
#include <memory>

// #include <uva/var.hpp>
// #include <uva/file.hpp>
// #include <uva/xml.hpp>
// #include <console.hpp>

// #include <uva-ui/app.hpp>
// #include <uva-ui/frame.hpp>
// #include <uva-ui/theme.hpp>
// #include <uva-ui/style.hpp>

#include <andy/lang/api.hpp>
#include <andy/lang/extension.hpp>

#include "app_class.cpp"
#include "frame_class.cpp"
#include "dialog_class.cpp"

class uvaui_extension : public andy::lang::extension
{
public:
    uvaui_extension()
        : andy::lang::extension("uva-ui")
    {
    }
protected:
    std::shared_ptr<andy::lang::object> application_instance;
public:
    virtual void load(andy::lang::interpreter* interpreter) override
    {
        auto UIClass = std::make_shared<andy::lang::structure>("UI");

        auto AppClass = create_app_class(interpreter);
        auto FrameClass = create_frame_class(interpreter);
        auto DialogClass = create_dialog_class(interpreter);

        auto app_obj    = andy::lang::object::create(interpreter, interpreter->ClassClass, AppClass);
        auto frame_obj  = andy::lang::object::create(interpreter, interpreter->ClassClass, FrameClass);
        auto dialog_obj = andy::lang::object::create(interpreter, interpreter->ClassClass, DialogClass);

        app_obj->cls->instance_methods["new"].call(app_obj);
        app_obj->cls->instance_methods["new"].call(frame_obj);
        app_obj->cls->instance_methods["new"].call(dialog_obj);

        UIClass->class_variables = {
            { "Application", app_obj    },
            { "Frame",       frame_obj  },
            { "Dialog",      dialog_obj },
        };

        interpreter->load(UIClass);
    }

    virtual void start(andy::lang::interpreter* interpreter) override
    {
        auto UI = interpreter->find_class("UI");

        if(!UI) {
            throw std::runtime_error("UI namespace not found");
        }

        auto AppClass = UI->class_variables["Application"]->as<std::shared_ptr<andy::lang::structure>>();

        if(AppClass->deriveds.empty()) {
            throw std::runtime_error("UI.Application has no derived classes");
        }

        application_instance = andy::lang::object::instantiate(interpreter, AppClass->deriveds.front(), nullptr);
    }
};

extern "C" {
    andy::lang::extension* create_extension()
    {
        return new uvaui_extension();
    }
}