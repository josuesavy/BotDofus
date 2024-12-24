#ifndef ANOMALYSUBAREAINFORMATIONRESPONSEMESSAGE_H
#define ANOMALYSUBAREAINFORMATIONRESPONSEMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/AnomalySubareaInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AnomalySubareaInformationResponseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AnomalySubareaInformationResponseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AnomalySubareaInformationResponseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AnomalySubareaInformationResponseMessage(FuncTree tree);
  AnomalySubareaInformationResponseMessage();

  QList<AnomalySubareaInformation> subareas;

private:
  void _subareastreeFunc(Reader *input);
  void _subareasFunc(Reader *input);

  FuncTree _subareastree;
};

#endif // ANOMALYSUBAREAINFORMATIONRESPONSEMESSAGE_H