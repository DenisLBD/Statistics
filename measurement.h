#pragma once

//класс, описывающий измерения, содержит параметры:
//номер измерения, результат измерения и время измерения
class Measurement
{
private:

  int number;
  double data;
  double time;
public:

  Measurement();

  int getNumber();

  double getData();

  double getTime();

  void setNumber(int numToSet);

  void setData(double dataToSet);

  void setTime(double timeToSet);
};


