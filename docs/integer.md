# Integer - целые числа

## Следующие функции включены в `../modules/integer/integer.h`

### ABS_Z_N.cpp

```c++
natural ABS_Z_N(const integer& a);
```
Принимает целое число. Возвращает его абсолютное значение, натуральное число.

### ADD_ZZ_Z.cpp

```c++
integer ADD_ZZ_Z(const integer& a, const integer& b);
```
Принимает два целых числа. Возвращает их сумму, целое число.

### COM_ZZ_D.cpp

```c++
ordinal COM_ZZ_D(const integer& left, const integer& right);
```
Принимает два целых числа. Возвращает результат их сравнения. Результаты сравнения определены в `../structs/ordinal.h`
```c++
ordinal::LT;  // Меньше
ordinal::EQ;  // Равно
ordinal::GT;  // Больше
```
```c++
bool operator == (const integer& left, const integer& right);
```
Оператор соответствия для целых определён в этом файле.

### DIV_ZZ_Z.cpp

```c++
integer DIV_ZZ_Z(const integer& a, const integer& b);
```
Функция принимает два целых числа и возвращает неполное частное от их деления, целое число.
При передаче в качестве второго оператора нуля бросает исключение.
`std::invalid_argument("Divided by zero")`

### INV_Z_Z.cpp

```c++
integer INV_Z_Z(const integer& a);
```
Функция принимает целое число и возвращает целое число равное по модулю, но противоположное по знаку.

### MOD_ZZ_Z.cpp

```c++
integer MOD_ZZ_Z(const integer& a, const integer& b);
```
Функция принимает два целых числа и возвращает остаток от их деления, целое число.
При передаче в качестве второго оператора нуля бросает исключение.
`std::invalid_argument("Divided by zero")`

### MUL_ZZ_Z.cpp

```c++
integer MUL_ZZ_Z(const integer& a, const integer& b);
```
Функция принимает два целых числа и возвращает их произведение, целое число.
```c++
integer integer::operator*(const integer& other);
```
Оператор умножения для натуральных определён в этом файле.

### POZ_Z_D.cpp

```c++
IntegerState POZ_Z_D(const integer& a);
```
Функция принимает целое число и возвращает его состояние. Состояния определены в `../structs/state.h`
```c++
IntegerState::Negative;  // Отрицательное
IntegerState::Zero;      // Ноль
IntegerState::Positive;  // Положительное
```

### SUB_ZZ_Z.cpp

```с++
integer SUB_ZZ_Z(const integer& a, const integer& b);
```
Принимает два целых числа и возвращает целое - их разность.

### TRANS_N_Z.cpp

```с++
integer TRANS_N_Z(natural a);
```
Функция принимает натуральное число и возвращает положительное целое, равное по модулю.

### TRANS_Z_N.cpp

```c++
natural TRANS_Z_N(integer a);
```
Функция принимает целое число и возвращает натуральное, равное по модулю.