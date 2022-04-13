# BigNum-class
能够完成100位以内的较大整数的加法和减法计算

BigNum类的数据成员包括：
①私有数据成员：数值域num(char []型)。
BigNum类成员函数包括：
①有参构造函数BigNum(char c[])和拷贝构造函数BigNum(const  BigNum  &)，其中有参构造函数参数默认值为"+0"，输出信息"BigNum Constructor run"，拷贝构造函数输出信息"BigNum CopyConstructor run"
②析构函数，析构函数输出信息"BigNum Destructor run"
③公有函数成员void  setNum(char c[])和char const *getNum(void) const分别返回和设置数值域。
④重载“+”运算符，实现两个BigNum对象相加的运算
⑤重载“-”运算符，实现两个BigNum对象相减的运算
⑥公有成员函数void show() const用于显示BigNum对象的信息，显示格式为：BigNum(<数值域>)
