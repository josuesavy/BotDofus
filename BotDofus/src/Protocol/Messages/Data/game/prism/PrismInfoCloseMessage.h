#ifndef PRISMINFOCLOSEMESSAGE_H
#define PRISMINFOCLOSEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PrismInfoCloseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismInfoCloseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismInfoCloseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismInfoCloseMessage(FuncTree tree);
  PrismInfoCloseMessage();
};

#endif // PRISMINFOCLOSEMESSAGE_H