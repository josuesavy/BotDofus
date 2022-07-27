#ifndef MOUNTINFORMATIONREQUESTMESSAGE_H
#define MOUNTINFORMATIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountInformationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountInformationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountInformationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountInformationRequestMessage(FuncTree tree);
  MountInformationRequestMessage();

  double id;
  double time;

private:
  void _idFunc(Reader *input);
  void _timeFunc(Reader *input);
};

#endif // MOUNTINFORMATIONREQUESTMESSAGE_H