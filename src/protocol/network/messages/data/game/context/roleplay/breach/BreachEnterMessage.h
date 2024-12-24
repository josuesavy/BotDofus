#ifndef BREACHENTERMESSAGE_H
#define BREACHENTERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BreachEnterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachEnterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachEnterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachEnterMessage(FuncTree tree);
  BreachEnterMessage();

  double owner;

private:
  void _ownerFunc(Reader *input);
};

#endif // BREACHENTERMESSAGE_H