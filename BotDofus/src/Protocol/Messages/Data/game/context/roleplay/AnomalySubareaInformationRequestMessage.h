#ifndef ANOMALYSUBAREAINFORMATIONREQUESTMESSAGE_H
#define ANOMALYSUBAREAINFORMATIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AnomalySubareaInformationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AnomalySubareaInformationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AnomalySubareaInformationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AnomalySubareaInformationRequestMessage(FuncTree tree);
  AnomalySubareaInformationRequestMessage();
};

#endif // ANOMALYSUBAREAINFORMATIONREQUESTMESSAGE_H