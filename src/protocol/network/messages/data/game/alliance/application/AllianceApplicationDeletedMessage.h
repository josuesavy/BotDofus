#ifndef ALLIANCEAPPLICATIONDELETEDMESSAGE_H
#define ALLIANCEAPPLICATIONDELETEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceApplicationDeletedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceApplicationDeletedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceApplicationDeletedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceApplicationDeletedMessage(FuncTree tree);
  AllianceApplicationDeletedMessage();

  bool deleted;

private:
  void _deletedFunc(Reader *input);
};

#endif // ALLIANCEAPPLICATIONDELETEDMESSAGE_H