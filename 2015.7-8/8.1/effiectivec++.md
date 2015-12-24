### Effective C++
1. 视C++为一个语言联邦
2. 尽量以const, enums and inlines to #defines. √
3. 尽可能使用const √

    ```
    return const_cast<char&>(
            static_cast<const TextBlock&>(*this)[postion]
        );
    ```
4. 确定对象被使用前已现被初始化 √
5. 了解C++默默编写并调用哪些函数
6. 若不想使用编译器自动生成的函数，就该明确拒绝
    ```
    声明为private而不定义
    不在该类本身而在一个基类中
    ```

7. 为多态基类声明virtual析构函数 √
8. 别让异常逃离析构函数
    ```
    析构函数不要抛出异常，应选择捕捉异常，然后不传播或结束程序
    应提供一个普通函数处理异常
    ```
9. 绝不在构造和析构函数中调用virtual函数
    ```
    与java/c#不同
    在构造期间子类被识别为基类
    ```
10. 令operator=返回一个*this的引用 √
11. 在operator=中处理自我赋值
    ```
    确保党对象自我赋值时operator=有良好的行为
    包括比较来源和目标的地址，语句顺序和copy-and-swap
    ```

12. 复制对象时复制每一个成分
    ```
    复制所有local成员变量
    调用所有base class内适当的copying函数
    不要试图以某个copying函数实现另一个
    ```
13. 以对象管理资源
14. 在资源管理类中小心copying行为
    ```
    不可复制
    引用计数
    ```
15. 在资源管理类中提供对原始资源的访问 ???
16. 成对使用new和delete时要采取相同的形式 √
17. 以独立语句将newed对象置入智能指针 √
18. 让接口容易被正确接收，不易被误用
19. 设计class犹如设计type
20. 宁以pass-by-reference-to-const代替pass-by-value
21. 必须返回对象时，别妄想返回其reference √
22. 将成员变量声明为private √
23. 宁以non-member,non-friend替换member函数
    ```
    面向对象守则要求数据应该尽可能被封装
    ```
24. 若所有参数皆需类型转换，请为此采用non-member函数
25. 考虑写出一个不抛异常的swap函数 !!!
26. 尽可能延后变量定义式的出现时间
    ```
    for(;;) {
        Widget w(i);
    }
    除非效率非常重要
    ```
27. 尽量少做转型动作
    ```
    const_cast通常被用来将对象的常量性转除
    dynamic_cast主要用来执行安全向下转型
    reinterpret_cast意图执行低级转型，不可移植
    static_cas用来强迫隐式转换，例如将non-const转为const,int转为double，无法将const转为non-const
    ```
28. 避免返回handles指向对象内容部分
29. 为“异常安全”而努力是值得的 ????
30. 透彻了解inling的里里外外
    ```
    隐喻申请：
        函数定义在类内
    编译器可能会拒绝将带有循环的函数作为inline
    virtual不能inline
    inline需要重新编译，ouline只需重新链接
    ```
31. 将文件间的编译依存关系降至最低
32. 确定你的public继承塑模出is-a关系 √
33. 避免遮掩继承而来的名称
34. 区分接口继承和实现继承
35. 考虑virtual函数以外的其他选择
    ```
    non-virtual
    function pointer
    tr1::function
    ```
36. 绝不重新定义继承而来的non-virtual函数 !!!
37. 绝不重新定义继承而来的缺省参数值 !!!
38. 通过复合塑模初has-a或根据某物实现出
39. 明智而谨慎地使用private继承
    ```
    并不存在is-a关系，但其中一个要访问另一个的protected成员或实现虚函数，使用private继承
    ```
40. 明智而谨慎地使用多重继承
41. 了解隐式接口和编译期多态 
42. 了解typename的双重意义
43. 学习处理模板化基类内的名称
44. 将与参数无关的代码抽离templates
45. 运用成员函数模板接受所有兼容类型
    ```
    template<typename T>
    public:
        template<typename U>
        SmartPtr(const SmartPtr<U>& other)
        : heldPtr(other.get()) {...}
        T* get*() const {return heldPtr;}
    private:
        T* heldPtr;
    ```
46. 需要类型转换时为模板定义非成员函数 ???
    ```
    编写一个class template，而它所提供的“与此template相关的”函数支持所有参数的隐式类型转换时，将那些函数定义为“class template”内部的friend函数
    ```
47. 使用traits classes表现类型信息 ???!!!
48. 认识template元编程 !!!!!!
49. 了解new-handle的行为
50. 了解new和delete的合理替换时机 ???
51. 编写new和delete时需固守常规
52. 了解placement new也要写placement delete
53. 不要忽视编译器的警告 √
54. 让自己熟悉包括TR1在内的标准程序库
55. 让自己熟悉boost !!!

### More Effective C++
1. 区分指针和引用
    ```
    char *pc = 0;
    char & rc = *pc;
    //未定义行为
    ```
2. 优先考虑C++风格的转换
    ```
    dynamic_cast 不能用于没有虚函数的类型
    ```
3. 决不要把多态应用于数组
4. 避免不必要的默认构造函数
5. 小心用户自定义的转换函数
6. 区分自增自减运算符的前缀和后缀形式
7. 不要重载&& || 和 , √
8. 理解new和delete在不同情形下的含义
9. 使用析构函数防止资源泄露
10. 防止构造函数里的资源泄露
11. 阻止异常传递到析构函数以外 !!!!!
12. 理解抛出异常与传递参数或者调用虚函数之间的不同
13. 通过引用捕获异常
14. 审慎地使用异常规格
15. 理解异常处理所付出的代价
16. 记住80-20准则 √
17. 考虑使用延迟计算
18. 分期摊预期的计算开销
19. 了解临时对象的来源 ！！！
20. 协助编译器实现返回值优化
    ```
    返回带有参数的构造函数而不是直接返回对象
    inline
    ```
21. 通过函数重载避免隐式类型转换
22. 考虑使用 op= 来取代单独的op运算符
23. 考虑使用其他等价的程序库
24. 理解虚函数、多重继承、虚基类以及RTTI所带来的开销
25. 使构造函数和非成员函数具有虚函数的行为
26. 限制类对象的个数
27. 要求或禁止对象分配在堆上
28. 智能指针
29. 引用计数
30. 代理类
31. 基于多个对象的虚函数
32. 在将来时态下开发程序
33. 将非尾端类设计为抽象类
34. 理解如何在同一程序中混合使用C和C++
35. 让自己熟悉C++语言标准

### Effective Mordern C++
1. Understand template type deduction