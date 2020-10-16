#ifndef STATISTICDATASTRING_H
#define STATISTICDATASTRING_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/common/basic/StatisticData.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class StatisticDataString : public StatisticData
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatisticDataString(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatisticDataString(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatisticDataString(FuncTree tree);
  StatisticDataString();
  bool operator==(const StatisticDataString &compared);

  QString value;

private:
  void _valueFunc(Reader *input);
};

#endif // STATISTICDATASTRING_H