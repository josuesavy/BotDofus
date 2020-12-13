#ifndef SPOUSEGETINFORMATIONSMESSAGE_H
#define SPOUSEGETINFORMATIONSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class SpouseGetInformationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpouseGetInformationsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpouseGetInformationsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpouseGetInformationsMessage(FuncTree tree);
  SpouseGetInformationsMessage();
};

#endif // SPOUSEGETINFORMATIONSMESSAGE_H