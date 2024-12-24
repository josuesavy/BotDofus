#ifndef FORCEACCOUNTERRORMESSAGE_H
#define FORCEACCOUNTERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ForceAccountErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ForceAccountErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ForceAccountErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ForceAccountErrorMessage(FuncTree tree);
  ForceAccountErrorMessage();
};

#endif // FORCEACCOUNTERRORMESSAGE_H