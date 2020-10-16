#ifndef BREACHCHARACTERSMESSAGE_H
#define BREACHCHARACTERSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BreachCharactersMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachCharactersMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachCharactersMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachCharactersMessage(FuncTree tree);
  BreachCharactersMessage();

  QList<double> characters;

private:
  void _characterstreeFunc(Reader *input);
  void _charactersFunc(Reader *input);

  FuncTree _characterstree;
};

#endif // BREACHCHARACTERSMESSAGE_H