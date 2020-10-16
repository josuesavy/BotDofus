#ifndef CHANGETHEMEREQUESTMESSAGE_H
#define CHANGETHEMEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ChangeThemeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChangeThemeRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChangeThemeRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChangeThemeRequestMessage(FuncTree tree);
  ChangeThemeRequestMessage();

  int theme;

private:
  void _themeFunc(Reader *input);
};

#endif // CHANGETHEMEREQUESTMESSAGE_H