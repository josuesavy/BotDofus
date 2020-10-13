#ifndef PRISMINFOINVALIDMESSAGE_H
#define PRISMINFOINVALIDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PrismInfoInValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismInfoInValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismInfoInValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismInfoInValidMessage(FuncTree tree);
  PrismInfoInValidMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // PRISMINFOINVALIDMESSAGE_H