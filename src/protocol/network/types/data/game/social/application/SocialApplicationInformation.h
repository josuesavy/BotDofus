#ifndef SOCIALAPPLICATIONINFORMATION_H
#define SOCIALAPPLICATIONINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class SocialApplicationInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialApplicationInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialApplicationInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialApplicationInformation(FuncTree tree);
  SocialApplicationInformation();
  bool operator==(const SocialApplicationInformation &compared);

   playerInfo;
  QString applyText;
  double creationDate;

private:
  void _playerInfotreeFunc(Reader *input);
  void _applyTextFunc(Reader *input);
  void _creationDateFunc(Reader *input);

  FuncTree _playerInfotree;
};

#endif // SOCIALAPPLICATIONINFORMATION_H