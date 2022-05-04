% vim: ft=tex
\documentclass[12pt]{article}
%\usepackage{lmodern}

\usepackage{cuprum}
\usepackage[T1]{fontenc}

\usepackage{multirow}

\usepackage{booktabs}% def toprule, midrule and etc.
%\usepackage[a5paper, twocolumn]{geometry}
\usepackage[a4paper, twocolumn]{geometry}
%\usepackage[a6paper]{geometry}
\geometry{vmargin=2cm, hmargin=0.2cm}
\usepackage{tikz}
\usepackage{environ}
\usepackage{fancyhdr}
\usepackage{xcolor,colortbl}

\pagestyle{fancy}
\renewcommand{\title}[1]{\fancyhead[C]{\textbf{\LARGE{ #1 }}}}
\fancyfoot[C]{\tiny Achtung! Diese Checkliste entbindet nicht von der Verpflichtung, die im Flughandbuch veröffentlichten Betriebs und Notverfahren zu befolgen.}  

\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0pt}

% creates empty checkboxes to be used as the second
% argument to \item on checklist
\newcommand{\checkbox}{\makebox[3ex][r]{\Large{$\square$}}}

% draws a dashed box around to group checklists
% a task has a title, which is the group title
\NewEnviron{task}{\par
\begin{tikzpicture}
\node[rectangle,minimum width=0.9\linewidth] (m)
  {\begin{minipage}{0.85\linewidth}
    \begin{center}\vspace{0.5em}\BODY\end{center}
   \end{minipage}};
\draw[solid](m.south west) rectangle (m.north east);
\end{tikzpicture}\vspace{0.5em}
}

% checklist env sets up a table and format the items.
% in case a item has steps use the \step{asdf}
% command.
\newenvironment{checklist}[1]{%
  \renewcommand{\item}[2]{%
    %\textbf{##1}\dotfill\makebox{\textbf{\uppercase{##2}}}\\
    ##1\dotfill\makebox{\uppercase{##2}}\\
  }
  \newcommand{\hint}[1]{%
    \small\hspace*{0.8em}##1\\
  }
  
  \newcommand{\decision}[1]{%
    \textbf{##1}\\
  }
  \newcommand\vertbar{\kern1pt\rule[-\dp\strutbox]{.8pt}{\baselineskip}\kern1pt}
  
  \newcommand{\step}[1]{%
    \hspace*{0.5em}\vertbar\hspace*{\labelsep}##1\\
  }
  \begin{tabular}{p{0.8\linewidth}}
       \multicolumn{1}{c}{\cellcolor{black!75}\color{white}\textbf{\uppercase{#1}}}\\
       \vspace{0.25em}
}{\end{tabular}\vspace{1em}}