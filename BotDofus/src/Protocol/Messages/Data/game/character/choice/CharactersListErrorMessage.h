#ifndef CHARACTERSLISTERRORMESSAGE_H
#define CHARACTERSLISTERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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