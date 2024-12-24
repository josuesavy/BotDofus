#ifndef NUGGETSDISTRIBUTIONMESSAGE_H
#define NUGGETSDISTRIBUTIONMESSAGE_H

#include "src/protocol/network/types/data/game/nuggets/NuggetsBeneficiary.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class NuggetsDistributionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NuggetsDistributionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NuggetsDistributionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NuggetsDistributionMessage(FuncTree tree);
  NuggetsDistributionMessage();

  QList<NuggetsBeneficiary> beneficiaries;

private:
  void _beneficiariestreeFunc(Reader *input);
  void _beneficiariesFunc(Reader *input);

  FuncTree _beneficiariestree;
};

#endif // NUGGETSDISTRIBUTIONMESSAGE_H