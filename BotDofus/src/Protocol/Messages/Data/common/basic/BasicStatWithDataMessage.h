#ifndef BASICSTATWITHDATAMESSAGE_H
#define BASICSTATWITHDATAMESSAGE_H

#include "src/Protocol/Types/Data/common/basic/StatisticData.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/common/basic/BasicStatMessage.h"

class BasicStatWithDataMessage : public BasicStatMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicStatWithDataMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicStatWithDataMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicStatWithDataMessage(FuncTree tree);
  BasicStatWithDataMessage();

  QList<QSharedPointer<StatisticData>> datas;

private:
  void _datastreeFunc(Reader *input);
  void _datasFunc(Reader *input);

  FuncTree _datastree;
};

#endif // BASICSTATWITHDATAMESSAGE_H