#ifndef STATISTICDATASHORT_H
#define STATISTICDATASHORT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/common/basic/StatisticData.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class StatisticDataShort : public StatisticData
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatisticDataShort(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatisticDataShort(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatisticDataShort(FuncTree tree);
  StatisticDataShort();
  bool operator==(const StatisticDataShort &compared);

  int value;

private:
  void _valueFunc(Reader *input);
};

#endif // STATISTICDATASHORT_H