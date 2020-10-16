#ifndef STATISTICDATA_H
#define STATISTICDATA_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class StatisticData : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatisticData(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatisticData(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatisticData(FuncTree tree);
  StatisticData();
  bool operator==(const StatisticData &compared);
};

#endif // STATISTICDATA_H