Sub ConvertCellsToNumeric()
    For col = 11 To 12:
        Dim i As Integer

        i = 10

        Do While ActiveSheet.Cells(i, col).Value <> ""
            ActiveSheet.Cells(i, col).Select

            With ActiveCell
                .Value = CDbl(.Value)
            End With
        Loop
    Next col
End Sub
