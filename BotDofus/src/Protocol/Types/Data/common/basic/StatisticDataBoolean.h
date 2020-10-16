#ifndef STATISTICDATABOOLEAN_H
#define STATISTICDATABOOLEAN_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/common/basic/StatisticData.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class StatisticDataBoolean : public StatisticData
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatisticDataBoolean(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatisticDataBoolean(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatisticDataBoolean(FuncTree tree);
  StatisticDataBoolean();
  bool operator==(const StatisticDataBoolean &compared);

  bool value;

private:
  void _valueFunc(Reader *input);
};

#endif // STATISTICDATABOOLEAN_H