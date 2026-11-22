|Symbol         | Meaning                   |
|:-------------:|--------------------------:|
|::=            |   Is defined as           |
|\|             | OR(alternative)           |
|*              | Zero or more              |
|+              | One or more               |
|?              | Zero or one(optional)     |
|( )            | Group expressions         |
|' '            | Literal text or character |
|\<match\> '...'| Match a regular expression|

## Source File:

    file                ::= file_element*
    file_element        ::= command_invocation line_ending | 
                            (bracket_comment | space)* line_ending
    line_ending         ::= line_comment? newline
    space               ::= <match '[ \t]+'>
    newline             ::= <match '\n'>

## Command Invocations:

    command_invocation  ::= space* identifier space* '(' arguments ')'
    identifier          ::= <match '[A-Za-z_][A-Za-z0-9_]*'>
    arguments           ::= argument? separated_arguments*
    separated_arguments ::= separation+ argument? | separation* '   ('arguments ')'
    separation          ::= space | line_ending`

## Command arguments:

    argument ::= bracket_argument | quoted_argument | unquoted_argument

## Bracket Argument:

    bracket_argument ::= bracket_open bracket_content bracket_close
    bracket_open     ::= '[' '='* '['
    bracket_content  ::= <any text not containing a bracket_close with
                         the same number of '=' as the bracket_open>
    bracket_close    ::= ']' '='* ']'

## Quoted Argument:

    quoted_argument     ::= '"' quoted_element* '"'
    quoted_element      ::= <any character except '\' or '"'> |
                            escape_sequence |
                            quoted_continuation
    quoted_continuation ::= '\' newline

## Unquoted Argument:

    unquoted_argument ::= unquoted_element+ | unquoted_legacy
    unquoted_element  ::= <any character except whitespace or one of '()#"\'> |
                          escape_sequence
    unquoted_legacy   ::= <see note in text>

## Escape Sequences:

    escape_sequence  ::= escape_identity | escape_encoded | escape_semicolon
    escape_identity  ::= '\' <match '[^A-Za-z0-9;]'>
    escape_encoded   ::= '\t' | '\r' | '\n'
    escape_semicolon ::= '\;'
