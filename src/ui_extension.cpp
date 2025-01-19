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

#include <extension/extension.hpp>
#include <interpreter/interpreter.hpp>

#include <uva/lang/ui/app_class.hpp>
#include <uva/lang/ui/frame_class.hpp>
#include <uva/lang/ui/dialog_class.hpp>

class uvaui_extension : public uva::lang::extension
{
public:
    uvaui_extension()
        : uva::lang::extension("uva-ui")
    {
    }
protected:
    std::shared_ptr<uva::lang::object> application_instance;
public:
    virtual void load(uva::lang::interpreter* interpreter) override
    {
        auto AppClass = uva::lang::app_class::create(interpreter);
        auto FrameClass = uva::lang::frame_class::create(interpreter);
        auto DialogClass = uva::lang::dialog_class::create(interpreter);

        interpreter->load(AppClass);
        interpreter->load(FrameClass);
        interpreter->load(DialogClass);
    }

    virtual void start(uva::lang::interpreter* interpreter) override
    {
        auto AppClass = interpreter->find_class("UI.Application");

        if(AppClass->deriveds.empty()) {
            throw std::runtime_error("UI.Application has no derived classes");
        }

        application_instance = uva::lang::object::instantiate(interpreter, AppClass->deriveds.front(), nullptr);
    }
};

UVA_EXTENSION(uvaui_extension);