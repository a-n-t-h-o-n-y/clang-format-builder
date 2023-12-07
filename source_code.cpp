#include <vector>
#include <initializer_list>
#include <vector>
#include <functional>
#include <optional>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include <string>
#include <array>
#include <map>

#define SOME_MACRO(x) (x * x)
#define ANOTHER_MACRO(y) [y](int a){ return a + y; }
#define MULTI_LINE_MACRO(x, y) \
    if ((x) > (y)) {           \
        std::cout << (x)       \
                  << " is greater than " \
                  << (y) << std::endl;   \
    } else {                   \
        std::cout << (x)       \
                  << " is not greater than " \
                  << (y) << std::endl;   \
    }


namespace LevelOneNamespace {
namespace LevelTwoNamespace {

// Class to test various formatting rules
class TestFormatter {
public:
    TestFormatter() : memberVar(0) {}

    void publicMethod() {
        if (condition) {
            std::cout << "Aligned if-statement" << std::endl;
        }
    }

protected:
    int protectedMethod() {
        for (int i = 0; i < 10; ++i) {
            memberVar += i;
        }
        return memberVar;
    }

private:
    int memberVar;
};

// Struct to test alignment and spacing
struct TestStruct {
    int a;
    double b;
    std::string c;
};

void functionWithParams(int a, double b, const std::string& c) {
    std::map<int, std::string> testMap = {
        {1, "One"},
        {2, "Two"}
    };

    auto lambda = [](int x) { return x * x; };
    auto iil = [](int x) { return x * x; }(5);
    auto result = lambda(5);
}

int test1() {
    TestFormatter formatter;
    formatter.publicMethod();

    TestStruct testStruct{1, 3.14, "Test"};
    functionWithParams(testStruct.a, testStruct.b, testStruct.c);

    return 0;
}

enum Color { RED, GREEN, BLUE };

template <typename T>
class TemplateClass {
public:
    TemplateClass(T value) : value_(value) {}

    void display() const {
        std::cout << "Template value: " << value_ << std::endl;
    }

private:
    T value_;
};

void testOperators() {
    const int a = 5;
    int b = 10;
    int const c = a + b;
    int d = (a * b) - c;

    bool comparisonResult = (a == b) && (c != d);
    if (comparisonResult) {
        std::cout << "Operators aligned" << std::endl;
    }
}

// Lambda expressions and auto type
void testLambdasAndAuto() {
    auto lambda = [](const auto& x, const auto& y) {
        auto const z = x + y;
        return 25 < y;
    };

    std::vector<int> vec = {10, 20, 5, 1500, 1000000};
    std::sort(vec.begin(), vec.end(), lambda);
}

int test2() {
    TemplateClass<int> intTemplate(10);
    intTemplate.display();

    testOperators();
    testLambdasAndAuto();

    Color favoriteColor = GREEN;
    switch (favoriteColor) {
        case RED:
            std::cout << "Favorite color is Red" << std::endl;
            break;
        case GREEN:
            std::cout << "Favorite color is Green" << std::endl;
            break;
        case BLUE:
            std::cout << "Favorite color is Blue" << std::endl;
            break;
        default:
            std::cout << "Unknown color" << std::endl;
    }

    return 0;
}

// Advanced class with nested structures and template specializations
template <typename T>
class AdvancedClass {
public:
    struct NestedStruct {
        int nestedMember;
    };

    AdvancedClass() : value_(0) {}

    template <typename U>
    U specializedFunction(U param) {
        return param * static_cast<U>(value_);
    }

private:
    T value_;
};

// Specialize the template function for int
template <>
int AdvancedClass<int>::specializedFunction<int>(int param) {
    return param + value_;
}

// Testing control flow structures and bitfields
class BitfieldTest {
public:
    BitfieldTest() : flag1(0), flag2(1) {}

    void controlFlowTest() {
        int x = 10, y = 20;
        if (x < y)
            std::cout << "x is less than y" << std::endl;
        else
            std::cout << "y is less or equal to x" << std::endl;
    }

private:
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
};

void smartPointerTest() {
    std::unique_ptr<AdvancedClass<double>> ptr(new AdvancedClass<double>());
    // Use ptr...
}

[[nodiscard]] int testAttributes() {
    return 42;
}

int test3() {
    AdvancedClass<double> advancedInstance;
    auto result = advancedInstance.specializedFunction(3.14);

    BitfieldTest bitfieldInstance;
    bitfieldInstance.controlFlowTest();

    smartPointerTest();
    int attributeTest = testAttributes();

    return 0;
}

// Function with a trailing return type
auto longFunctionWithTrailingReturnType(const std::string& reallyLongParameterName, int anotherLongParameterName) -> std::function<void()> {
    // This comment is intentionally made very long to test the comment wrapping behavior in the clang-format configuration. The line length exceeds 120 characters to see how it wraps.
    return [&]() {
        std::cout << "This is a lambda with a really, really long message to demonstrate line wrapping behavior. The message is designed to exceed 120 characters." << std::endl;
    };
}

// Class with long member names and function declarations
class ClassWithVeryLongMemberNamesAndFunctionDeclarations {
public:
    ClassWithVeryLongMemberNamesAndFunctionDeclarations() : veryLongMemberVariableNameForTestingPurpose(0) {}

    void functionWithExceedinglyLongNameToTestTheWrappingBehaviorOfFunctionDeclarations(int parameterWithLongName, double anotherParameterWithLongName);

private:
    int veryLongMemberVariableNameForTestingPurpose;
};

void ClassWithVeryLongMemberNamesAndFunctionDeclarations::functionWithExceedinglyLongNameToTestTheWrappingBehaviorOfFunctionDeclarations(int parameterWithLongName, double anotherParameterWithLongName) {
    // Implementing a function with a very long name to see how it affects the formatting and line wrapping.
    std::cout << "This function has a very long name and parameters to test line wrapping in clang-format." << std::endl;
}

int test4() {
    ClassWithVeryLongMemberNamesAndFunctionDeclarations longNamedClass;
    longNamedClass.functionWithExceedinglyLongNameToTestTheWrappingBehaviorOfFunctionDeclarations(42, 3.14);

    auto trailingReturnTypeFunction = longFunctionWithTrailingReturnType("This is a very long string to test parameter wrapping in functions with trailing return types", 12345);
    trailingReturnTypeFunction();

    return 0;
}

class StringListTest {
public:
    StringListTest()
        : listWithTrailingComma({
            "Eclipse", "Horizon", "Nebula", "Quasar", "Galaxy",
            "Comet", "Asteroid", "Meteor", "Orbit", "Cosmos",
          }),
          listWithoutTrailingComma({
            "Quantum", "Atom", "Neutron", "Electron", "Photon",
            "Proton", "Meson", "Boson", "Quark", "Lepton"
          }) {}

private:
    std::vector<std::string> listWithTrailingComma;
    std::vector<std::string> listWithoutTrailingComma;
};

int test5() {
    // while loop example
    int counter = 0;
    while (counter < 5) {
        std::cout << "Counter: " << counter << std::endl;
        ++counter;
    }

    while(true) {
        break;
    }

    // do-while loop example
    do {
        std::cout << "Executing at least once, counter: " << counter << std::endl;
        --counter;
    } while (counter > 0);

    // std::algorithm with long lambda invocation
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::for_each(numbers.begin(), numbers.end(), [](int number) {
        std::cout << "Number squared: " << number * number << std::endl;
    });

    // Another std::algorithm example with inline iterators and lambda
    std::vector<int> values(10);
    std::iota(values.begin(), values.end(), 1); // Fill with 1, 2, ..., 10
    auto result = std::find_if(values.begin(), values.end(), [](int val) {
        return val > 5; // Find the first value greater than 5
    });

    if (result != values.end()) {
        std::cout << "First value greater than 5: " << *result << std::endl;
    }

    return 0;
}

template <typename T>
class Outer {
    template <typename U>
    class Inner {
    public:
        Inner(U u) : value(u) {}
    private:
        U value;
    };

public:
    Outer(T t) : inner(t) {}

private:
    Inner<T> inner;
};

class MyClass {
public:
    MyClass(std::initializer_list<std::vector<int>> list) : data(list) {}

private:
    std::vector<std::vector<int>> data;
};

MyClass obj{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
MyClass obj2{{1, 2, 3}, {44, 5, 6}, {7, 80, 9},};

void test6() {
    int x = 5;
    auto lambda = [y = std::move(x), z = x + 1]() {
        std::cout << "y: " << y << ", z: " << z << std::endl;
    };
    lambda();
}

template <typename... Args>
class VariadicTemplate {
public:
    void printSize() {
        std::cout << "Number of template parameters: " << sizeof...(Args) << std::endl;
    }
};

VariadicTemplate<int, double, char> obj;

class [[nodiscard]] MyAttributeClass {
public:
    [[nodiscard]] int criticalFunction() const {
        return 42;
    }
};

alignas(16) int alignedVariable = 0;

void test7() {
    auto obj = MyAttributeClass {};
    auto result = obj.criticalFunction();
    std::cout << "Result: " << result << std::endl;
    std::cout << "Aligned variable: " << alignedVariable << std::endl;
}


struct S {int x; double y;};

class C {
  public:
    C& operator+=(const C&) { if(c) d++; return *this; } 
    C operator+ (const C& o) { return C(*this) += o; }
    C& operator-() { toggle(); return *this; }  
  private:
    void toggle() { negate ? negate = false : negate = true; }  
    bool negate{false}; int c{0}; double d{0.0};
};   

struct B {
  B() = default;
  B(const B&) = delete; 
  int x{0}; double y{0.0};
};

template <typename T> 
concept C1 = requires(T x) {
  {x + x} -> std::convertible_to<int>;
  {x - x} -> std::same_as<decltype(x)>;
};


  template <C1 T>
  auto add(T x, T y) -> T {
    return x + y; 
  }

  []<typename T>(std::vector<T> v) -> decltype(auto) {
    for (T x : v) {}
    return v;
  }(std::vector{1, 2});    

}
}

int main() {

  auto x = cond1 ? throw E{} : 
      cond2 ? val2 :
          !cond3 ? val3 :
              val4;

  using Func = std::optional<std::function<double(double)>>;  
  Func f = [](double x) { return 2*x; };

  S arr[2][5]; 
  int (*ap)[5] = arr; 

  auto operator ""_mi(long double x) {
    return x * 1609.344;
  }
  const auto d = 10.5_mi;

  auto [x, y] = get_pair();

}
