#ifndef CHARACTERSLISTERRORMESSAGE_H
#define CHARACTERSLISTERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CharactersListErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharactersListErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharactersListErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharactersListErrorMessage(FuncTree tree);
  CharactersListErrorMessage();
};

#endif // CHARACTERSLISTERRORMESSAGE_H