#include <memory>

namespace uva
{
    namespace lang
    {
        class interpreter;
        class structure;

        namespace dialog_class
        {
            std::shared_ptr<uva::lang::structure> create(uva::lang::interpreter* interpreter);
        };
    };
};
