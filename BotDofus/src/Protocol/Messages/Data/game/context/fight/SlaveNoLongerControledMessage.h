#ifndef SLAVENOLONGERCONTROLEDMESSAGE_H
#define SLAVENOLONGERCONTROLEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class SlaveNoLongerControledMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SlaveNoLongerControledMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SlaveNoLongerControledMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SlaveNoLongerControledMessage(FuncTree tree);
  SlaveNoLongerControledMessage();

  double masterId;
  double slaveId;

private:
  void _masterIdFunc(Reader *input);
  void _slaveIdFunc(Reader *input);
};

#endif // SLAVENOLONGERCONTROLEDMESSAGE_H