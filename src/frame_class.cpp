#include <uva/lang/ui/frame_class.hpp>
#include <interpreter/interpreter.hpp>

#include <uva/file.hpp>
#include <uva/ui/frame.hpp>

#include <object.hpp>
#include <class.hpp>

#include <uva/widgets.hpp>
#include <uva/xml.hpp>

#include <uva/lang/ui/toplevel_class.hpp>

std::shared_ptr<uva::lang::structure> uva::lang::frame_class::create(uva::lang::interpreter* interpreter)
{
    return uva::lang::toplevel_class<uva::ui::frame>::create(interpreter, "UI.Frame");
}