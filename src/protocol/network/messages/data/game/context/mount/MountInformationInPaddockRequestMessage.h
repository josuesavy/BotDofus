#ifndef MOUNTINFORMATIONINPADDOCKREQUESTMESSAGE_H
#define MOUNTINFORMATIONINPADDOCKREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountInformationInPaddockRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountInformationInPaddockRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountInformationInPaddockRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountInformationInPaddockRequestMessage(FuncTree tree);
  MountInformationInPaddockRequestMessage();

  int mapRideId;

private:
  void _mapRideIdFunc(Reader *input);
};

#endif // MOUNTINFORMATIONINPADDOCKREQUESTMESSAGE_H