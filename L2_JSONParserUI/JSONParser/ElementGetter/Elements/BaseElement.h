#ifndef BASEELEMENT_H
#define BASEELEMENT_H

#include <string>
#include <map>
#include <vector>
#include <memory>


enum class elementType
{
    OBJECT, LIST,
    STRING, NUMBER,
    BOOLEAN, NULL_TYPE
};

enum class elementValueType
{
    MAP, VECTOR,
    STRING, FLOAT,
    BOOLEAN
};

class BaseElement;
using JSONObject = std::map<std::string, std::shared_ptr<BaseElement>>;
using JSONList = std::vector<std::shared_ptr<BaseElement>>;

struct ElementValue
{
    ElementValue() {}

    elementValueType type;
    union{
        std::shared_ptr<JSONObject> object;
        std::shared_ptr<JSONList> list;
        std::shared_ptr<std::string> sValue;
        float fValue;
        bool bValue;
    };

    ~ElementValue() {}
};

class BaseElement
{
public:
    virtual elementType getType();
    virtual std::shared_ptr<ElementValue> getValue();

    virtual void setValue(std::shared_ptr<ElementValue> value);

    virtual std::string toString() = 0;

private:
    elementType _type;
    std::shared_ptr<ElementValue> _value;
};

#endif // BASEELEMENT_H
