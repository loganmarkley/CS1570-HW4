template <typename T>
T updateMoney(T currentMoney, bool isCorrect)
{
  if(isCorrect)
    return currentMoney*2;
  else
    return currentMoney-100;
}
