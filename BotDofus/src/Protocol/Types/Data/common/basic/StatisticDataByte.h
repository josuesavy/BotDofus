#ifndef STATISTICDATABYTE_H
#define STATISTICDATABYTE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/common/basic/StatisticData.h"
#include "src/engines/io/network/utils/FuncTree.h"

class StatisticDataByte : public StatisticData
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatisticDataByte(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatisticDataByte(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatisticDataByte(FuncTree tree);
  StatisticDataByte();
  bool operator==(const StatisticDataByte &compared);

  int value;

private:
  void _valueFunc(Reader *input);
};

#endif // STATISTICDATABYTE_H