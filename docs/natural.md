# Natural - натуральные числа

## Следующие функции включены в `../modules/natural/natural.h`

### `ADD_1N_N.cpp`

```c++
natural ADD_1N_N(const natural& n);
```
Функция инкремента.
Принимает натуральное число, возвращает число на единицу больше.

### `ADD_NN_N.cpp`

```c++
natural ADD_NN_N(const natural& a, const natural& b);
```
Функция сложения.
Принимает два натуральных числа, возвращает их сумму.
```c++
natural natural::operator+(const natural& other);
```
Оператор сложения для натуральных определён в этом файле.

### `COM_NN_D.cpp`

```c++
ordinal COM_NN_D(const natural& l, const natural& r);
```
Функция сравнения. Принимает два натуральных числа, возвращает результат их сравнения. Результаты сравнения определены в `../structs/ordinal.h`
```c++
ordinal::LT;  // Меньше
ordinal::EQ;  // Равно
ordinal::GT;  // Больше
```

### `DIV_NN_Dk.cpp`

```c++
std::pair<digit,std::int16_t> DIV_NN_Dk(const natural& a, const natural& b);
```
Функция, возвращающая первую цифру деления. Принимает два натуральных, возвращает пару из цифры и разряда, результата деления.
```c++
auto a = DIV_NN_Dk(b, c);
a.first;  // Цифра
a.second;  // Разряд
```
При передаче в качестве второго оператора нуля бросает исключение.
`std::invalid_argument("Second operand is equal to zero")`

### `DIV_NN_N.cpp`

```c++
natural DIV_NN_N(const natural& a, const natural& b);
```
Функция принимает два натуральных числа и возвращает неполное частное от их деления, натуральное число.
При передаче в качестве второго оператора нуля бросает исключение.
`std::invalid_argument("Your divider is equal to zero")`
```c++
natural natural::operator/(const natural& other);
```
Оператор деления для натуральных определён в этом файле.

### `GCF_NN_N.cpp`

```c++
natural GCF_NN_N(const natural& a, const natural& b);
```
Функция принимает два натуральных числа и возвращает их НОД, натуральное число.

### `LCM_NN_N.cpp`

```c++
natural LCM_NN_N(const natural& a, const natural& b);
```
Функция принимает два натуральных числа и возвращает их НОК, натуральное число.

### `MOD_NN_N.cpp`

```c++
natural MOD_NN_N(const natural& a, const natural& b);
```
Функция принимает два натуральных числа и возвращает остаток от их деления, натуральное число.
При передаче в качестве второго оператора нуля бросает исключение.
`std::invalid_argument("Your divider is equal to zero")`
```c++
natural natural::operator%(const natural& other);
```
Оператор остатка от деления для натуральных определён в этом файле.

### `MUL_ND_N.cpp`

```c++
natural MUL_ND_N(const natural &a, const digit &n);
```
Функция принимает натуральное число и цифру и возвращает результат умножения числа на цифру, натуральное число.

### `MUL_Nk_N.cpp`

```c++
natural MUL_Nk_N(const natural &value, const int &power);
```
Функция принимает натуральное число и степень(`int`) и возвращает результат умножения натурального числа на десять в степени, натуральное число.

### `MUL_NN_N.cpp`

```c++
natural MUL_NN_N(const natural &a, const natural &b);
```
Функция принимает два натуральных числа и возвращает их произведение, натуральное число.

### `NZER_N_B.cpp`

```c++
bool NZER_N_B (const natural& a);
```
Функция принимает натуральное число и возвращает `true`, если это ноль, иначе `false`

### `SUB_NDN_N.cpp`

```c++
natural SUB_NDN_N(const natural& a, const natural& b, const digit& n);
```
Функция принимает два натуральных числа и цифру и возвращает результат вычитания из первого второго умноженного на цифру, натуральное число.
Если результат умножения второго числа на цифру больше первого бросает исключение
`std::invalid_argument("Result is negative")`

### `SUB_NN_N.cpp`

```c++
natural SUB_NN_N(const natural& a, const natural& b);
```
Функция принимает два натуральных числа и возвращает результат их вычитания, натуральное число. Первое натуральное должно быть больше либо равно второму.
```c++
natural natural::operator-(const natural& other);
```
Оператор вычитания для натуральных определён в этом файле.