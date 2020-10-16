#ifndef STATISTICDATAINT_H
#define STATISTICDATAINT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/common/basic/StatisticData.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class StatisticDataInt : public StatisticData
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatisticDataInt(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatisticDataInt(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatisticDataInt(FuncTree tree);
  StatisticDataInt();
  bool operator==(const StatisticDataInt &compared);

  int value;

private:
  void _valueFunc(Reader *input);
};

#endif // STATISTICDATAINT_H