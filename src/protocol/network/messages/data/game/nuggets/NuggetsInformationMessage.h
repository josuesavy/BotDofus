#ifndef NUGGETSINFORMATIONMESSAGE_H
#define NUGGETSINFORMATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class NuggetsInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NuggetsInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NuggetsInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NuggetsInformationMessage(FuncTree tree);
  NuggetsInformationMessage();

  int nuggetsQuantity;

private:
  void _nuggetsQuantityFunc(Reader *input);
};

#endif // NUGGETSINFORMATIONMESSAGE_H