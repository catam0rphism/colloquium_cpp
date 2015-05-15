# Fraction - рациональные числа

## Следующие функции включены в `../modules/fractional/fractional.h`

### ADD_QQ_Q.cpp

```c++
fraction ADD_QQ_Q(fraction a, fraction b);
```
Принимает два рациональных числа. Возвращает их сумму, рациональное число.

### COM_QQ_D.cpp

```c++
ordinal COM_QQ_D(const fraction& left, const fraction& right);
```
Принимает два рациональных числа. Возвращает результат их сравнения. Результаты сравнения определены в `../structs/ordinal.h`
```c++
ordinal::LT;  // Меньше
ordinal::EQ;  // Равно
ordinal::GT;  // Больше
```
```c++
bool operator == (const fraction& left, const fraction& right);
```
Оператор соответствия для рациональных определён в этом файле.

### DIV_QQ_Q.cpp

```c++
fraction DIV_QQ_Q(const fraction &a, const fraction &b);
```
Функция принимает два рациональных числа и возвращает результат их деления, рациональное число.

### INT_Q_B.cpp

```c++
bool INT_Q_B(fraction Q_2);
```
Функция принимает рациональное число и возвращает `true` если оно является целым и `false` если не является

### MUL_QQ_Q.cpp

```c++
fraction MUL_QQ_Q(fraction Num1, fraction Num2);
```
Функция принимает два рациональных числа и возвращает их произведение, рациональное число.

### RED_Q_Q.cpp

```c++
fraction RED_Q_Q(const fraction &RED);
```
Функция принимает рациональное число и возвращает его же, только сокращённое.

### SUB_QQ_Q.cpp

```c++
fraction SUB_QQ_Q(const fraction &fract_1, const fraction &fract_2);
```
Функция принимает два рациональных числа и возвращает результат их вычитания, рациональное число.

### TRANS_Q_Z.cpp

```c++
integer TRANS_Q_Z(const fraction& Q);
```
Функция принимает рациональное число и возвращает его целый аналог.

### TRANS_Z_Q.cpp

```c++
fraction TRANS_Z_Q(const integer& Z);
```
Функция принимает целое число и возвращает соответствующее рациональное со знаменателем '1'.