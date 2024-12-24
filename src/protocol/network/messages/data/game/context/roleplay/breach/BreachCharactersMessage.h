#ifndef BREACHCHARACTERSMESSAGE_H
#define BREACHCHARACTERSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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