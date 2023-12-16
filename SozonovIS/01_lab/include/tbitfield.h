// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>

using namespace std;

typedef unsigned int TELEM;

class TBitField
{
private:
  int  BitLen; // длина битового поля - макс. к-во битов
  TELEM *pMem; // память для представления битового поля
  int  MemLen; // к-во эл-тов Мем для представления бит.поля

  // методы реализации
  int   GetMemIndex(const int n) const; // индекс в pМем для бита n       (#О2)
  TELEM GetMemMask (const int n) const; // битовая маска для бита n       (#О3)
  int BitsInMem = 16; // универс в куске памяти
  int shiftSize = 4; // смещение на k бит
public:
  TBitField(int len);                //                                   (#О1)
  TBitField(const TBitField &bf);    //                                   (#П1)
  ~TBitField();                      //                                    (#С)

  // доступ к битам
  int GetLength(void) const;      // получить длину (к-во битов)           (#О)
  void SetBit(const int n);       // установить бит                       (#О4)
  void ClrBit(const int n);       // очистить бит                         (#П2)
  int  GetBit(const int n) const; // получить значение бита               (#Л1)

  // битовые операции
  int operator==(const TBitField &bf) const; // сравнение                 (#О5)
  int operator!=(const TBitField &bf) const; // сравнение
  TBitField& operator=(const TBitField &bf); // присваивание              (#П3)
  TBitField  operator|(const TBitField &bf); // операция "или"            (#О6)
  TBitField  operator&(const TBitField &bf); // операция "и"              (#Л2)
  TBitField  operator~(void);                // отрицание                  (#С)

  // перегрузка ввода/вывода
  friend istream& operator>>(istream& istr, TBitField& bf)       //ввод    (#О7)
  {
      cout << "Enter bit string: ";
      string BitField;
      istr >> BitField;
      if (BitField.length() > bf.BitLen)
          throw exception("Out of range");
      for (int i = 0; i < BitField.length(); i++)
          if (BitField[i] == '1')
              bf.SetBit(i);
          else
              bf.ClrBit(i);
      return istr;
  }

  friend ostream& operator<<(ostream& ostr, const TBitField& bf) //вывод    (#П4)
  {
      for (int i = bf.BitLen - 1; i >= 0; i--)
          if (bf.GetBit(i))
              ostr << "1";
          else
              ostr << "0";
      return ostr;
  }
};
// Структура хранения битового поля
//   бит.поле - набор битов с номерами от 0 до BitLen
//   массив pМем рассматривается как последовательность MemLen элементов
//   биты в эл-тах pМем нумеруются справа налево (от младших к старшим)
// О8 Л2 П4 С2

#endif
