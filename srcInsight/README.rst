
Using Custom Language Files
=================================

Custom Language files add syntax formatting and some parsing support to Source Insight for languages that are not built-in.

Files with .xclf extension are used for Source Insight version 4 and newer. Files with .clf extension are used for version 3.x.

To import a custom language file into Source Insight:

    Select Options > Preferences. Click the Languages tab.
    Click the Import button. Select and load the custom language file (extension .clf for v3, and .xclf for v4). You should now see the new language in the list of languages.
    Click the File Types button to open the File Type Options dialog box.
    If you don't have a file type already created for the type of language file, you will need to create one now. If you already have a file type created, select it in the list and go to step 7.
    Click the Add Type button to create a new file type.  Give it a name that describes the type of file. For example, "Ant File". Click OK and then fill in the file filter text box with a wildcard.  For example, "*.ant".
    In the Parsing section of the File Type Options dialog box, select the newly imported language in the language drop-down list. This is what associates your file type with the custom language.
    Click the Close button to close File Type Options. Then click OK to close the Preferences dialog box.

